import pygame

import time

import RPi.GPIO as gp


 

gp.setmode(gp.BCM)

gp.setup(17,gp.IN)

pygame.init()

 

state=True

btncnt = 0

 

 

try:

    while True:

        btn = gp.input(17)

        if btn==1:

            if state :

                state = False

                btncnt+=1

                if btncnt==1:

                    print("count : "+str(btncnt))

                    pygame.mixer.music.load('/home/pi/Music/aespa.mp3')

                    pygame.mixer.music.play()

                    #playsound(m1)

                elif btncnt==2:

                    print("count : "+str(btncnt))

                    pygame.mixer.music.pause()

		    btncnt = 0

        elif btn == 0:

            state = True

            

except KeyboardInterrupt:

 

    gp.cleanup()