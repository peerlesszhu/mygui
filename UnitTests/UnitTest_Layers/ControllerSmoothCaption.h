/*!
	@file
	@author		Albert Semenov
	@date		11/2009
	@module
*/

#ifndef __CONTROLLER_SMOOTH_CAPTION_H__
#define __CONTROLLER_SMOOTH_CAPTION_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_WidgetDefines.h"
#include "MyGUI_ControllerItem.h"

namespace demo
{

	class ControllerSmoothCaption :
		public MyGUI::ControllerItem
	{
		MYGUI_RTTI_DERIVED( ControllerSmoothCaption );

	public:
		ControllerSmoothCaption() { }
		virtual ~ControllerSmoothCaption() { }

	private:
		bool addTime(MyGUI::WidgetPtr _widget, float _time)
		{
			const float slice = 0.04;
			mTime += _time;
			if (mTime > slice)
			{
				mTime -= slice;
				update(_widget);
			}

			return true;
		}

		void prepareItem(MyGUI::WidgetPtr _widget)
		{
			mTime = 0;
			mCurrentPosition = 0;

			_widget->eventChangeProperty = MyGUI::newDelegate(this, &ControllerSmoothCaption::notifyChangeProperty);
		}

		void update(MyGUI::WidgetPtr _widget)
		{
			if (mCurrentPosition < mNeedCaption.size())
			{
				mCurrentPosition ++;
				if (mCurrentPosition == mNeedCaption.size())
					_widget->setCaption(mNeedCaption);
				else
					_widget->setCaption(mNeedCaption.substr(0, mCurrentPosition) + " _");
			}
		}

		void notifyChangeProperty(MyGUI::WidgetPtr _sender, const std::string& _key, const std::string& _value)
		{
			if (_key == "Widget_Caption")
			{
				mNeedCaption = _value;
				mCurrentPosition = 0;
				_sender->setCaption("");
			}
		}

	private:
		float mTime;
		std::string mNeedCaption;
		size_t mCurrentPosition;

	};

}

#endif // __CONTROLLER_SMOOTH_CAPTION_H__