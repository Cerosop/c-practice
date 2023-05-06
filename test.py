import matplotlib.pyplot as plt
from keras.applications.vgg16 import (VGG16, decode_predictions,
                                      preprocess_input)

import keras.utils as image 
import numpy as np
from numpy import asarray, expand_dims
from PIL import Image


def predict(path: str, feature_size: int) -> list[tuple]:
    x = image.img_to_array(image.load_img(path, target_size=(224, 224)))
    x = expand_dims(x, axis=0)
    return decode_predictions(model.predict(preprocess_input(x)), top=feature_size)[0]


def showimg(path: str, imgname: str) -> None:
    plt.figure(figsize=(20, 10))
    # plt.subplot(2, 5, 1)
    plt.title(imgname)
    plt.axis('off')
    plt.imshow(asarray(Image.open(path)))
    plt.show()
    
    
model = VGG16(weights = 'imagenet')
path = "192.jpg"
results = predict(path, 15)
for result in results:
    print(result)
name = results[np.argmax(np.array(results), axis = 0)[2]][1]
showimg(path, name)