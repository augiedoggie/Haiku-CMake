#include <Application.h>
#include <StringView.h>
#include <Window.h>


class HelloView : public BView {
public:
	HelloView(BRect frame)
		:
		BView(frame, "HelloView", B_FOLLOW_ALL, B_WILL_DRAW)
	{
		SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

		BStringView* text = new BStringView(BRect(20, 20, 260, 40), "HelloText",
			"Hello from UseHaiku.cmake!");
		AddChild(text);
	}
};


class HelloWindow : public BWindow {
public:
	HelloWindow()
		:
		BWindow(BRect(100, 100, 380, 200), "HelloHaiku Example", B_TITLED_WINDOW,
			B_NOT_ZOOMABLE | B_NOT_RESIZABLE)
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
		BApplication("application/x-vnd.Haiku-CMake-HelloHaiku")
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
