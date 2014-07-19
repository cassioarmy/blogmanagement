/***************************************************************************
 *   Copyright (C) 2014 by Cássio Alexandre de Sousa <cassio.army@gmail.com>                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "blogmanagement.h"
#include <KDE/KApplication>
#include <KDE/KAboutData>
#include <KDE/KCmdLineArgs>
#include <KDE/KLocale>

static const char description[] =
    I18N_NOOP("A KDE 4 Application");

static const char version[] = "0.1";

int main(int argc, char **argv)
{
    KAboutData about("blogmanagement", 0, ki18n("BlogManagement"), version, ki18n(description),
                     KAboutData::License_GPL, ki18n("(C) 2014 Cássio Alexandre de Sousa"), KLocalizedString(), 0, "cassio.army@gmail.com");
    about.addAuthor( ki18n("Cássio Alexandre de Sousa"), KLocalizedString(), "cassio.army@gmail.com" );
    KCmdLineArgs::init(argc, argv, &about);

    KCmdLineOptions options;
    options.add("+[URL]", ki18n( "Document to open" ));
    KCmdLineArgs::addCmdLineOptions(options);
    KApplication app;

    BlogManagement *widget = new BlogManagement;

    // see if we are starting with session management
    if (app.isSessionRestored())
    {
        RESTORE(BlogManagement);
    }
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
        if (args->count() == 0)
        {
            //blogmanagement *widget = new blogmanagement;
            widget->show();
        }
        else
        {
            int i = 0;
            for (; i < args->count(); i++)
            {
                //blogmanagement *widget = new blogmanagement;
                widget->show();
            }
        }
        args->clear();
    }

    return app.exec();
}
