#pragma once

#include "Core/Window.h"
#include "SDL2/SDL.h"

namespace AE
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline u32 GetWidth() const override { return _Data.width; }
		inline u32 GetHeight() const override { return _Data.height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { _Data.eventCallback = callback;  }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		SDL_Window* _Window;
		SDL_Surface* _Surface;

		struct WindowData
		{
			std::string title;
			u32 width;
			u32 height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData _Data;
	};
}
