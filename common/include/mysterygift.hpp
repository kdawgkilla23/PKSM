/*
 *   This file is part of PKSM
 *   Copyright (C) 2016-2020 Bernardo Giordano, Admiral Fish, piepie62
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
 *       * Requiring preservation of specified reasonable legal notices or
 *         author attributions in that material or in the Appropriate Legal
 *         Notices displayed by works containing it.
 *       * Prohibiting misrepresentation of the origin of that material,
 *         or requiring that modified versions of such material be marked in
 *         reasonable ways as different from the original version.
 */

#ifndef MYSTERYGIFT_HPP
#define MYSTERYGIFT_HPP

#include "Gender.hpp"
#include "Sav.hpp"
#include "Species.hpp"
#include "WCX.hpp"
#include "nlohmann/json_fwd.hpp"
#include <bzlib.h>
#include <string>

namespace MysteryGift
{
    struct giftData
    {
        giftData(const std::string& name = "", const std::string& game = "", int species = 0, int form = 0, Gender gender = Gender::Male,
            bool released = false)
            : name(name), game(game), species(species), form(form), gender(gender), released(released)
        {
        }
        std::string name;
        std::string game;
        int species;
        int form;
        Gender gender;
        bool released;
    };

    void init(Generation gen);
    std::vector<nlohmann::json> wondercards();
    giftData wondercardInfo(size_t index);
    std::unique_ptr<WCX> wondercard(size_t index);
    void exit();
}

#endif
