// common.h
//
// Copyright (C) 2012 - Sebastian Geiger
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

typedef struct {
    GtkWidget    *tasks;
    GtkWidget    *applet;
    GtkWidget    *title;
    GSettings    *settings;
    
    /* This is needed to activate a window when the user drags
     * a string onto a task item.
     *
     * last_window_for_activation:
     * This is the pointer to the task-item which was last 
     * registered to the timer function.
     */
    GtkWidget   *last_window_for_activation;
    /*
     * This is the id of the timer that will activate the
     * window which last_window_for_activation points to.
     * We need it if we want to cancel the timer when the
     * user decides to drag the string to another icon and
     * the time was not up yet.
     */
    guint        last_window_source_id;
} WinPickerApp;

/** 
 * The window picker app contains our reference to GSettings, putting it into
 * a common header file allow us to share it accross the different classes
 * of window picker.
 */
extern WinPickerApp *mainapp;

#define SHOW_WIN_KEY "show-all-windows"
#define SHOW_APPLICATION_TITLE_KEY "show-application-title"
#define SHOW_HOME_TITLE_KEY "show-home-title"
#define ICONS_GREYSCALE_KEY "icons-greyscale-mask"
#define EXPAND_TASK_LIST "expand-task-list"
