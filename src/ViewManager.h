/*
    Copyright (C) 2006-2007 by Robert Knight <robertknight@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301  USA.
*/

#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

// Qt
#include <QHash>
#include <QObject>
#include <QPointer>

class QSignalMapper;

class KActionCollection;
class KToggleAction;
class KXMLGUIFactory;

namespace Konsole
{

class MainWindow;
class Session;
class TerminalDisplay;
class Profile;

class SessionController;
class ViewProperties;
class ViewContainer;
class ViewSplitter;

/** 
 * Manages the terminal display widgets in a Konsole window or part.
 *
 * When a view manager is created, it constructs a splitter widget ( accessed via 
 * widget() ) to hold one or more view containers.  Each view container holds
 * one or more terminal displays and a navigation widget ( eg. tabs or a list )
 * to allow the user to navigate between the displays in that container.
 *
 * The view manager provides facilities to construct display widgets for a terminal
 * session and also to construct the SessionController which provides the menus and other
 * user interface elements specific to that display/session pair.
 *
 * The view manager provides a number of actions ( defined in the 'konsoleui.rc' XML file )
 * to manipulate the views and view containers - for example, actions to split the view
 * left/right or top/bottom, detach a view from the current window and navigate between
 * views and containers.  These actions are added to the collection specified in the 
 * constructor.
 */
class ViewManager : public QObject
{
Q_OBJECT

public:
    /** 
     * Constructs a new view manager with the specified @p parent.  
     * View-related actions defined in 'konsoleui.rc' are created
     * and added to the specified @p collection.    
     */
    ViewManager(QObject* parent , KActionCollection* collection);
    ~ViewManager();

    /**
     * Creates a new view to display the outout from and deliver input to @p session.
     * Constructs a new container to hold the views if no container has yet been created.
     */
    void createView(Session* session);

    /**
     * Merges views from another view manager into this manager.
     * Only views from the active container in the other manager are merged.
     */
    void merge(ViewManager* manager);

    /** 
     * Return the main widget for the view manager which
     * holds all of the views managed by this ViewManager instance.
     */
    QWidget* widget() const;

    /**
     * Returns the view manager's active view.
     */
    QWidget* activeView() const;

    /**
     * Returns the list of view properties for views in the active container.
     * Each view widget is associated with a ViewProperties instance which
     * provides access to basic information about the session being
     * displayed in the view, such as title, current directory and 
     * associated icon.     
     */
    QList<ViewProperties*> viewProperties() const;

signals:
    /** Emitted when the last view is removed from the view manager */
    void empty();

    /** Emitted when a session is detached from a view owned by this ViewManager */
    void viewDetached(Session* session);

    /** 
     * Emitted when the active view changes. 
     * @param controller The controller associated with the active view 
     */
    void activeViewChanged(SessionController* controller);

    /**
     * Emitted when the list of view properties ( as returned by viewProperties() ) changes.
     * This occurs when views are added to or removed from the active container, or 
     * if the active container is changed.
     */
    void viewPropertiesChanged(const QList<ViewProperties*>& propertiesList);

    // internal
    // 'multipleViews' - true if the manager has multiple containers or false otherwise
    void splitViewToggle(bool multipleViews);

    /** TODO: Document me. */
    void setMenuBarVisible(bool);

private slots:
    // called when the "Split View Left/Right" menu item is selected
    void splitLeftRight();
    void splitTopBottom();
    void closeActiveView();
    void closeOtherViews();

    // called when the "Detach View" menu item is selected
    void detachActiveView();
    // called when a session terminates - the view manager will delete any
    // views associated with the session
    void sessionFinished( Session* session );
    // called when the container requests to close a particular view
    void viewCloseRequest(QWidget* widget);

    // controller detects when an associated view is given the focus
    // and emits a signal.  ViewManager listens for that signal
    // and then plugs the action into the UI
    //void viewFocused( SessionController* controller );

    // called when the active view in a ViewContainer changes, so
    // that we can plug the appropriate actions into the UI
    void viewActivated( QWidget* view );

    // called when "Next View" shortcut is activated
    void nextView();

    // called when "Previous View" shortcut is activated
    void previousView();

    // called when "Next View Container" shortcut is activated
    void nextContainer();

    // called when the views in a container owned by this view manager
    // changes
    void containerViewsChanged(QObject* container);

    // called when a profile changes
    void profileChanged(const QString& key);

private:
    void setupActions();
    void focusActiveView();
    void registerView(TerminalDisplay* view);
    void unregisterView(TerminalDisplay* view);
  
    // takes a view from a view container owned by a different manager and places it in 
    // newContainer owned by this manager
    void takeView(ViewManager* otherManager , ViewContainer* otherContainer, ViewContainer* newContainer, TerminalDisplay* view); 
    void splitView(Qt::Orientation orientation);
    
    // creates a new container which can hold terminal displays
    ViewContainer* createContainer();
    // removes a container and emits appropriate signals
    void removeContainer(ViewContainer* container);

    // creates a new terminal display
    TerminalDisplay* createTerminalDisplay();
    // applies the view-specific settings such as colour scheme associated
    // with 'session' to 'view'
    void loadViewSettings(TerminalDisplay* view , Profile* profile);

    // creates a new controller for a session/display pair which provides the menu
    // actions associated with that view, and exposes basic information
    // about the session ( such as title and associated icon ) to the display.
    SessionController* createController(Session* session , TerminalDisplay* display);

private:
    MainWindow*          _mainWindow;
//    KToggleAction*              _splitViewAction;
    ViewSplitter*               _viewSplitter;
    QPointer<SessionController> _pluggedController;
    QHash<TerminalDisplay*,Session*> _sessionMap;
    KActionCollection*  _actionCollection;
    QSignalMapper* _containerSignalMapper;
};

};

#endif