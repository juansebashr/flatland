/*
 *  ______                   __  __              __
 * /\  _  \           __    /\ \/\ \            /\ \__
 * \ \ \L\ \  __  __ /\_\   \_\ \ \ \____    ___\ \ ,_\   ____
 *  \ \  __ \/\ \/\ \\/\ \  /'_` \ \ '__`\  / __`\ \ \/  /',__\
 *   \ \ \/\ \ \ \_/ |\ \ \/\ \L\ \ \ \L\ \/\ \L\ \ \ \_/\__, `\
 *    \ \_\ \_\ \___/  \ \_\ \___,_\ \_,__/\ \____/\ \__\/\____/
 *     \/_/\/_/\/__/    \/_/\/__,_ /\/___/  \/___/  \/__/\/___/
 * @copyright Copyright 2017 Avidbots Corp.
 * @name  world_plugin.h
 * @brief Interface for WorldPlugin pluginlib plugins
 * @author Yi Ren
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2017, Avidbots Corp.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Avidbots Corp. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FLATLAND_SERVER_WORLD_PLUGIN_H
#define FLATLAND_SERVER_WORLD_PLUGIN_H

#include <Box2D/Box2D.h>
#include <flatland_server/flatland_plugin.h>
#include <flatland_server/timekeeper.h>
#include <flatland_server/yaml_reader.h>
#include <ros/ros.h>
#include <yaml-cpp/yaml.h>

#include <string>

namespace flatland_server {
// forward declaration
class World;
class WorldPlugin : public FlatlandPlugin {
 protected:
  World *world_;
  YamlReader world_config_;

 public:
  /*
   * @brief WorldPlugin default constructor
   */
  WorldPlugin() = default;

  /*
   * @brief initialize the plugin
   * @param[in] world, the World the plugin is attached to
   * @param[in] name, name of the plugin
   * @param[in] type, type of the plugin
   * @param[in] plugin_reader, the YAML node contain the plugin's config
   * @param[in] world_config, the yaml reader of world.yaml
   */
  void Initialize(World *world, std::string name, std::string type,
                  YAML::Node &plugin_reader, YamlReader &world_config);
};
};  // namespace flatland_server

#endif  // FLATLAND_SERVER_WORLD_PLUGIN_H
