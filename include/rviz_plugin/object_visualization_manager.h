/*
 * Copyright © 2020 Ahmed Faisal Abdelrahman, Sushant Vijay Chavan All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright notice, this
 *       list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, this
 *       list of conditions and the following disclaimer in the documentation and/or
 *       other materials provided with the distribution.
 *     * Neither the name of “Hochschule Bonn-Rhein-Sieg” nor the names of its contributors
 *       may be used to endorse or promote products derived from this software without specific
 *       prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
  File: object_visualization_manager.h
  Purpose: RViz plugin for viewing and filtering 3D object meshes

  @author Ahmed Faisal Abdelrahman
  @author Sushant Vijay Chavan
  @version 1.0 15/08/20
*/

#ifndef OBJECT_VIS_MANAGER
#define OBJECT_VIS_MANAGER

#include <map>

#include <ros/ros.h>
#include <rviz/panel.h>
#include <rviz/default_plugin/marker_display.h>
#include <visualization_msgs/MarkerArray.h>
#include <rviz/default_plugin/markers/marker_base.h>

#include <OgreSceneNode.h>

namespace RVizVisualization
{

class ObjectVisualizationManager : public rviz::Panel
{
Q_OBJECT
public:
    ObjectVisualizationManager(QWidget* parent = 0);
    virtual ~ObjectVisualizationManager();

    virtual void onInitialize();

    virtual void load( const rviz::Config& config );
    virtual void save( rviz::Config config ) const;

protected:
    void markerArrayCb(const visualization_msgs::MarkerArray::ConstPtr& msg);

    void addNewMarker(const visualization_msgs::Marker& msg);
    void updateMarker(const visualization_msgs::Marker& msg);
    void deleteMarker(const int marker_id);
    rviz::MarkerBase* createMarker(const visualization_msgs::Marker& msg, 
                                                                Ogre::SceneNode* scene_node);

    ros::Subscriber marker_array_sub_;
    rviz::MarkerDisplay marker_display_;

    Ogre::SceneNode* root_scene_node_;

    typedef std::map<int, Ogre::SceneNode*> SceneMap;
    typedef std::map<int, rviz::MarkerBase*> MarkerMap;
    typedef std::pair<int, Ogre::SceneNode*> ScenePair;
    typedef std::pair<int, rviz::MarkerBase*> MarkerPair;
    typedef std::map<int, Ogre::SceneNode*>::iterator SceneMapItr;
    typedef std::map<int, rviz::MarkerBase*>::iterator MarkerMapItr;

    SceneMap scene_nodes_map_;
    MarkerMap markers_map_;
};

} // end namespace RVizVisualization

#endif // OBJECT_VIS_MANAGER
