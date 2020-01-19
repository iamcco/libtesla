/**
 * Copyright (C) 2020 WerWolv
 * 
 * This file is part of libtesla.
 * 
 * libtesla is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * libtesla is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with libtesla.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "overlay/elements/element.hpp"

#include <functional>

namespace tsl::element {

    class CustomDrawer : public Element {
    public:
        CustomDrawer(u16 x, u16 y, u16 w, u16 h, std::function<void(u16 x, u16 y, Screen *screen)> drawer);
        ~CustomDrawer();

        Element* requestFocus(Element *oldFocus, FocusDirection direction) {
            return nullptr;
        }

        void draw(Screen *screen, u16 x, u16 y) override;
        void layout() override;

    private:
        std::function<void(u16 x, u16 y, Screen *screen)> m_drawer;
    };

}