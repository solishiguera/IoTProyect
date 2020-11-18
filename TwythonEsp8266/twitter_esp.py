# Diego was here :)  

from twython import Twython
from firebase import firebase
import time

def tweetStuff(twitter, firebase): 
    """This function will tweet my room's temperature"""
    cycles = 0
    while cycles < 10:
        # Gets data from DB attribute
        result = firebase.get('Var','')
        print("Fetched data: ", result)
        anterior = result

        # Prevents status duplicates (error 403)
        if result == anterior: 
            result += 0.1 

        # Tweets message
        message = "Diego's room temperature is " + str(result) + "°C"
        twitter.update_status(status = message)
        print("Tweeted %s", message)

        anterior = result
        cycles += 1
        time.sleep(180)


def main():
    my_firebase = firebase.FirebaseApplication("https://XXXXXXXXXX.firebaseio.com/")

    # Consumer API keys and Access Tokens
    from my_keys import (
        consumer_key,
        consumer_secret,
        access_token,
        access_secret
    )

    twitter = Twython(
        consumer_key,
        consumer_secret,
        access_token,
        access_secret
    )

    tweetStuff(twitter, my_firebase)