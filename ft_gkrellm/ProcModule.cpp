/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProcModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:22:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/17 16:11:26 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProcModule.hpp"
#include <cstdio>

ProcModule::ProcModule( void ) : AMonitorModule('p', false) {}
ProcModule::ProcModule( ProcModule const & obj ) : AMonitorModule('p', false) { static_cast<void>(obj); }
ProcModule & ProcModule::operator=( ProcModule const & rhs ) { static_cast<void>(rhs); return *this; }

ProcModule::ProcModule( bool has_widget ) : AMonitorModule('p', has_widget) {
	if (this->_has_widget) {
		this->_box = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 5);
		this->_proc_label = Gtk::manage(new Gtk::Label("PROCESSES"));
		this->_proc_label->set_padding(5, 3);
		Gtk::Frame* frame;
		frame = Gtk::manage(new Gtk::Frame("Processes"));
		try { dynamic_cast<Gtk::Label*>(frame->get_label_widget())->set_markup("<b>Processes</b>"); } catch(std::exception) {}
		frame->add(*this->_proc_label);
		this->_box->pack_start(*frame);

		this->refresh();
	}
}

ProcModule::~ProcModule( void ) {
	if (this->_has_widget) delete this->_box;
}

void ProcModule::refresh( void ) {
	FILE		*info;
	char		buf[256];
	std::string	procinfo;

	info = popen("/usr/bin/top -l1 | /usr/bin/head -n1 | /usr/bin/tr ':,' '\\n\\n' | /usr/bin/tail -n5 | /usr/bin/sed 's/^[\t ]*//g'", "r");
	if (info == NULL) {
		this->_procinfo = "Information unavailable";
		return ;
	}
	while (fgets(buf, 256, info) != NULL) {
		procinfo.append(buf);
	}
	pclose(info);
	procinfo.erase(std::remove(procinfo.end()-1, procinfo.end(), '\n'), procinfo.end());
	this->_procinfo = procinfo;
	if (this->_has_widget) {
		this->_proc_label->set_text(this->_procinfo);
	}
}

int ProcModule::toTerminal(int row, int height) {
	if (height < 6) return 0;
	std::string out(std::string("Processes:\n") + this->_procinfo);
	// if (out.size() > static_cast<unsigned long>(COLS))
	// 	out.erase(COLS, std::string::npos);
	mvaddstr(row, 0, out.c_str());
	return 6;
}

Gtk::Widget* ProcModule::getWidget( void ) { return this->_box; }
