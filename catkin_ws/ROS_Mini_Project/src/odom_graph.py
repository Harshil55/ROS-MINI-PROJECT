#!/usr/bin/env python
import rospy
from nav_msgs.msg import Odometry

import pygame, sys
from pygame.locals import *

#Initiates the display
pygame.init()
windowSurfaceObj= pygame.display.set_mode((600,600))
pygame.display.set_caption('Husky Odom Graph')
yellow = pygame.Color(245,210,0)
windowSurfaceObj.fill(pygame.Color(0,0,0))
pygame.display.update()

old_x = 0.2
old_y = 0

#Callback function, draws a line from the last odom point to a new one
def odomCB(msg):
	global old_x
	global old_y
	new_x=10.0
	new_y=1.0
	pygame.draw.line(windowSurfaceObj, yellow, (old_x,old_y), (new_x, new_y), 2)
	pygame.display.update()
	
	old_x=new_x
	old_y=new_y

	

def listener():

	rospy.init_node('odom_graph', anonymous=True)

#     changed publish to read "twist_marker_server/cmd_vel"
#     change repairs issues under indigo 
	rospy.Subscriber("odometry/filtered", Odometry, odomCB)

	rospy.spin()

if __name__=="__main__":
	
	listener()
		
