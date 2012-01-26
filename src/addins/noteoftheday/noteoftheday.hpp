/*
 * mnote
 *
 * Copyright (C) 2009 Debarshi Ray
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __NOTE_OF_THE_DAY_HPP_
#define __NOTE_OF_THE_DAY_HPP_

#include <string>

#include <glibmm.h>

#include "sharp/dynamicmodule.hpp"
#include "applicationaddin.hpp"
#include "note.hpp"

namespace mnote {

class NoteManager;

}

namespace noteoftheday {

class NoteOfTheDay
{
public:

  static mnote::Note::Ptr create(mnote::NoteManager & manager,
                                 const Glib::Date & date);
  static void cleanup_old(mnote::NoteManager & manager);
  static std::string get_content(const Glib::Date & date,
                                 const mnote::NoteManager & manager);
  static mnote::Note::Ptr get_note_by_date(
                            mnote::NoteManager & manager,
                            const Glib::Date & date);
  static std::string get_template_content(
                       const std::string & title);
  static std::string get_title(const Glib::Date & date);
  static bool has_changed(const mnote::Note::Ptr & note);

  static const std::string s_template_title;

private:

  static std::string get_content_without_title(
                       const std::string & content);

  static const std::string s_title_prefix;
};

}

#endif
