from twython import Twython

# This is where I stored my Consumer API keys and Access Tokens
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

# This will tweet the phrase 'Hello world!'
message = "Hello world!"
twitter.update_status(status=message)
print("Tweeted %s", message)

# This will tweet three words in separate tweets
message = ["lol", "lmao", "ola"]
for i in range(len(message)):
    twitter.update_status(status=message[i])
    print("Tweeted %s", message)

# This will tweet an image
message = "me"
# IMG_3390.jpg is the name of my image
image = open('IMG_3390.jpg', 'rb')
response = twitter.upload_media(media=image)
media_id = [response['media_id']]
twitter.update_status(status=message, media_ids=media_id)
print("Tweeted %s", message)
