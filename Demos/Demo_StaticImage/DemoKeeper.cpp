/*!
    @file
    @author     Albert Semenov
    @date       08/2008
    @module
*/
#include "precompiled.h"
#include "DemoKeeper.h"
#include "Base/Main.h"

namespace demo
{

	void DemoKeeper::setupResources()
	{
		addResourceLocation("../../Media/Demos/Demo_StaticImage");
		addResourceLocation("../../Media/Common/Wallpapers");
		base::BaseManager::setupResources();
	}

    void DemoKeeper::createScene()
    {
        setWallpaper("wallpaper0.jpg");
        setDescriptionText("Simple ImageSet viewer implementation.");

		mView = new StaticImageView();
    }

    void DemoKeeper::destroyScene()
    {
		delete mView;
    }

} // namespace demo

MYGUI_APP(demo::DemoKeeper)
