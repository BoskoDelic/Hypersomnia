#pragma once
#include <vector>
#include "math/vec2.h"
#include "window_framework/event.h"
#include "misc/timer.h"
#include "graphics/pixel.h"
#include "texture_baker/texture_baker.h"
#include "texture_baker/font.h"
#include "rect.h"

namespace augs {
	namespace graphics {
		extern fpstimer fps;
		namespace gui {
			namespace text {
				struct formatted_char {
					augs::font* font_used;
					wchar_t c;
					unsigned char r, g, b, a;
					void set(wchar_t, augs::font* = 0, const rgba& = rgba());
					void set(augs::font* = 0, const rgba& = rgba());
				};

				struct style {
					augs::font* f;
					rgba color;
					style(augs::font* = nullptr, rgba = rgba());
					style(const formatted_char&);
					operator formatted_char();
				};

				typedef std::basic_string<formatted_char> fstr;
			}

			class system {
				bool 
					/* own_copy indicates whether the clipboard_change event comes from manual "copy_clipboard" or from external source */
					own_copy, 
					own_clip;
			public:
				augs::window::event::state& events;
				text::fstr clipboard;

				system(augs::window::event::state& subscribe_events);

				void change_clipboard();
				void copy_clipboard(text::fstr&);
				bool fetch_clipboard, is_clipboard_own();
			};

			class group {
				rect* focus;
			public:
				struct {
					material mat;
					rects::wh<float> size;
					vec2i pos;
					rect* subject;
					float speed_mult;
				} middlescroll;
				
				system& owner;
				rect *lholded, *rholded;

				rect root;
				std::vector<augs::vertex_triangle> quad_array;

				group(system& owner);

				void set_focus(rect*);
				rect* get_focus() const;

				void update_rectangles();
				void poll_events      ();
				void call_updaters    ();
				void update_array     ();
				void default_update   ();
				void draw_gl_fixed();
			};
				
			
			namespace text {
				extern fstr format(const std::wstring&, style);
				extern void format(const std::wstring&, style, fstr&);
				extern void format(const wchar_t*, style, fstr&);
				extern fstr format(const wchar_t*, style);
			}

			extern void paste_clipboard(text::fstr& out, text::formatted_char = text::formatted_char());
		}
	}
	namespace misc {
		extern std::wstring wstr(const graphics::gui::text::fstr& f);
		template <class T>
		T wnum(const graphics::gui::text::fstr& f) {
			std::wistringstream ss(wstr(f));
			T v;
			ss >> v;
			return v;
		}
		
	}
}

