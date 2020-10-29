/*
 * MIT License
 * 
 * Copyright (c) 2020 Ahmed Faisal Abdelrahman, Sushant Vijay Chavan
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef ABSTRACT_DATALOADER_H
#define ABSTRACT_DATALOADER_H

#include <ros/ros.h>
#include <mongodb_store/message_store.h>

namespace RVizDataLoader 
{
    class AbstractDataloader
    {
        public:
            AbstractDataloader(ros::NodeHandle nh) : message_proxy_(nh) {};
            virtual ~AbstractDataloader(){};

            virtual void queryDatabase() = 0;
            virtual void runDataUpdateLoop() = 0;
            virtual void publishObjectData() = 0;
    
        protected:
            mongodb_store::MessageStoreProxy message_proxy_;
            ros::Publisher data_pub_;
    };
}

#endif
