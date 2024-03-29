/*
 * mnote
 *
 * Copyright (C) 2009 Hubert Figuiere
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

#ifndef __BUGZILLA_INSERT_BUG_ACTION_HPP_
#define __BUGZILLA_INSERT_BUG_ACTION_HPP_

#include <string>

#include "undo.hpp"

#include "bugzillalink.hpp"

namespace bugzilla {

class InsertBugAction
  : public mnote::SplitterAction
{
public:
  InsertBugAction(const Gtk::TextIter & start, const std::string & id,
                  const BugzillaLink::Ptr & tag);
  void undo (Gtk::TextBuffer * buffer);
  void redo (Gtk::TextBuffer * buffer);
  void merge (EditAction * action);
  bool can_merge (const EditAction * action) const;
  void destroy ();

private:
  BugzillaLink::Ptr m_tag;
  int               m_offset;
  std::string       m_id;
};


}


#endif
