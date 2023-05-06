import matplotlib.pyplot as plt
from keras.callbacks import CSVLogger, EarlyStopping
from keras.datasets import fashion_mnist as fm
from keras.layers import Dense, Dropout, Flatten
from keras.models import Sequential
from keras.utils.np_utils import to_categorical

BATCH_SIZE = 48
EPOCHS = 20
CLASS_NAMES = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']


def show_train_images(tl, ti):
    plt.figure(figsize=(10, 10))
    for i in range(25):
        plt.subplot(5, 5, i + 1)
        plt.axis('off')
        plt.grid(False)
        plt.title(CLASS_NAMES[tl[i]])
        plt.imshow(ti[i].reshape(28, 28), cmap=plt.cm.binary)
    plt.show()


(train_images, train_labels), (test_images, test_labels) = fm.load_data()
train_images = train_images / 255
test_images = test_images / 255
# show_train_images(train_labels, train_images)
train_labels = to_categorical(train_labels, len(CLASS_NAMES))
test_labels = to_categorical(test_labels, len(CLASS_NAMES))

model = Sequential([
    Flatten(input_shape=(28, 28)),
    Dense(516, activation='relu'),
    Dropout(0.3),
    Dense(516, activation='relu'),
    Dropout(0.3),
    Dense(516, activation='relu'),
    Dropout(0.3),
    # Dense(64, activation='relu'),
    # Dropout(0.3),
    Dense(len(CLASS_NAMES), activation='softmax')
], name='TestSquentialModel')
model.compile(
    optimizer='rmsprop', loss='categorical_crossentropy', metrics=['accuracy'])
model.summary()

hist_result = model.fit(
    train_images, train_labels,
    batch_size=BATCH_SIZE, epochs=EPOCHS, validation_split=0.1,
    callbacks=[
        EarlyStopping(monitor='val_loss', patience=4),
        CSVLogger('training.log')
    ])
test_loss, test_acc = model.evaluate(test_images, test_labels)
print(f'\nTest loss: {test_loss}\nTest accuracy: {test_acc}')

losses = hist_result.history['loss']
val_losses = hist_result.history['val_loss']
epochs = range(len(losses))
plt.plot(epochs, losses, marker='.', label='loss(training data)')
plt.plot(epochs, val_losses, marker='.', label='val_loss(evaluation data)')
plt.legend(loc='best')
plt.grid()
plt.xlabel('epoch')
plt.ylabel('loss')
plt.show()