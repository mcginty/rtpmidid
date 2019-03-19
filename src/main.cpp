/**
 * Real Time Protocol Music Industry Digital Interface Daemon
 * Copyright (C) 2019 David Moreno Montero <dmoreno@coralbits.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include "./logger.hpp"
#include "./aseq.hpp"
#include "./stringpp.hpp"

using namespace std;
rtpmidid::aseq::aseq *seq = nullptr;


int main(int argc, char **argv){
    INFO("Real Time Protocol Music Industry Digital Interface Daemon - v0.1");
    INFO("(C) 2019 David Moreno Montero <dmoreno@coralbits.com> -- I'm a freelancer and accept contract jobs.");

    try{
      seq = new rtpmidid::aseq::aseq("rtpmidid");
      auto outputs = rtpmidid::aseq::get_outputs(seq);

      DEBUG("Outputs: {}", std::to_string(outputs));

    } catch (const std::exception &e){
      ERROR("{}", e.what());
      return 1;
    }
    return 0;
}