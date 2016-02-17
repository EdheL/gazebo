/*
 * Copyright (C) 2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_GUI_PLOT_PALETTE_HH_
#define _GAZEBO_GUI_PLOT_PALETTE_HH_

#include <memory>

#include "gazebo/gui/ConfigWidget.hh"
#include "gazebo/gui/qt.h"

#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace gui
  {
    // Forward declare private data class
    class PalettePrivate;

    /// \brief A special list widget that allows dragging of items from it to a
    /// plot
    class GZ_GUI_VISIBLE Palette : public QWidget
    {
      Q_OBJECT

      /// \brief Constructor
      /// \param[in] _parent Pointer to parent widget.
      public: Palette(QWidget *_parent);

      /// \brief Destructor
      public: ~Palette();

      /// \brief Fill the top panel of the topics tab.
      private: void FillTopics(QStandardItemModel *_topicsModel);

      /// \brief Fill a layout with properties from a protobuf message.
      /// Only plottable fields such as int, double and bool are displayed.
      /// \param[in] _msg A basic message from the topic's message type.
      /// \param[in] _uri The current URI.
      private: void FillFromMsg(google::protobuf::Message *_msg,
                   QStandardItem *_item, const std::string &_uri);

      /// \internal
      /// \brief Pointer to private data.
      private: std::unique_ptr<PalettePrivate> dataPtr;
    };
  }
}
#endif
