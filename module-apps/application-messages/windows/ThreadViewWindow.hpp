/*
 * @file ThreadViewWindow.hpp
 * @author Robert Borzecki (robert.borzecki@mudita.com)
 * @date 25 wrz 2019
 * @brief
 * @copyright Copyright (C) 2019 mudita.com
 * @details
 */
#ifndef MODULE_APPS_APPLICATION_MESSAGES_WINDOWS_THREADVIEWWINDOW_HPP_
#define MODULE_APPS_APPLICATION_MESSAGES_WINDOWS_THREADVIEWWINDOW_HPP_

#include <functional>
#include <string>

#include "AppWindow.hpp"
#include "gui/widgets/Image.hpp"
#include "gui/widgets/Label.hpp"
#include "gui/widgets/Window.hpp"
#include "ListView.hpp"

#include "../MessagesModel.hpp"

namespace gui {

/*
 *
 */
class ThreadViewWindow: public AppWindow {
protected:
  gui::Label *title = nullptr;
  MessagesModel* messagesModel = nullptr;
  std::shared_ptr<ThreadRecord> threadRecord;
  gui::ListView* list = nullptr;

public:
  ThreadViewWindow(app::Application *app);
  virtual ~ThreadViewWindow();

  // virtual methods
  bool onInput(const InputEvent &inputEvent) override;
  void onBeforeShow(ShowMode mode, uint32_t command, SwitchData *data) override;
  bool handleSwitchData( SwitchData* data );

  bool onDatabaseMessage( sys::Message* msgl );

  void rebuild() override;
  void buildInterface() override;
  void destroyInterface() override;
};

} /* namespace gui */

#endif /* MODULE_APPS_APPLICATION_MESSAGES_WINDOWS_THREADVIEWWINDOW_HPP_ */
