#include <Application.h>
#include <Catalog.h>
#include <StringView.h>
#include <Window.h>

#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "HelloHaikuI18nWindow"


class HelloView : public BView {
public:
	HelloView(BRect frame)
		:
		BView(frame, "HelloView", B_FOLLOW_ALL, B_WILL_DRAW)
	{
		SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

		BStringView* text = new BStringView(BRect(20, 20, 320, 40), "HelloText",
			B_TRANSLATE("Hello from UseHaiku.cmake!"));
		AddChild(text);
	}
};


class HelloWindow : public BWindow {
public:
	HelloWindow()
		:
		BWindow(BRect(100, 100, 440, 200), B_TRANSLATE("HelloHaikuI18n Example"),
			B_TITLED_WINDOW, B_NOT_ZOOMABLE | B_NOT_RESIZABLE)
	{
		AddChild(new HelloView(Bounds()));
	}

	bool QuitRequested() override
	{
		be_app->PostMessage(B_QUIT_REQUESTED);
		return true;
	}
};


class HelloApp : public BApplication {
public:
	HelloApp()
		:
		BApplication("application/x-vnd.Haiku-CMake-HelloHaikuI18n")
	{
	}

	void ReadyToRun() override
	{
		(new HelloWindow())->Show();
	}
};


int
main()
{
	HelloApp app;
	app.Run();
	return 0;
}
