import nltk

from nltk.corpus import movie_reviews

from nltk.tokenize import word_tokenize

from nltk.probability import FreqDist

from nltk.classify import NaiveBayesClassifier

from nltk.classify.util import accuracy

import matplotlib.pyplot as plt

nltk.download('movie_reviews')

nltk.download('punkt')

documents = [(list(movie_reviews.words(fileid)), category)

for category in movie_reviews.categories()

for fileid in movie_reviews.fileids(category)]

import random

random.shuffle(documents)

all_words = FreqDist(w.lower() for w in movie_reviews.words())

word_features = list(all_words.keys())[:2000]

def document_features(document):

document_words = set(document)

features = {}

for word in word_features:
  

features['contains({})'.format(word)] = (word in document_words)

return features

featuresets = [(document_features(d), c) for (d, c) in documents]

train_set = featuresets[:1500]

test_set = featuresets[1500:]

classifier = NaiveBayesClassifier.train(train_set)

accuracy_score = accuracy(classifier, test_set)

print("Classifier accuracy:", accuracy_score)

text = "I loved this movie! It was amazing."

tokens = word_tokenize(text)

features = document_features(tokens)

sentiment = "positive"

positive_reviews = len([c for (_, c) in test_set if c == 'pos'])

negative_reviews = len([c for (_, c) in test_set if c == 'neg'])

labels = ['Positive', 'Negative']

sentiments = [positive_reviews, negative_reviews]

colors = ['#66b3ff', '#ff9999']

plt.figure(figsize=(8, 6))

plt.pie(sentiments, labels=labels, autopct='%1.1f%%', startangle=140, colors=colors)

plt.title('Sentiment Distribution in Test Data (Pie Chart)')

plt.axis('equal') # Equal aspect ratio ensures that pie is drawn as a circle.

plt.show()

plt.figure(figsize=(8, 6))

plt.bar(labels, sentiments, color=colors)

plt.title('Sentiment Distribution in Test Data (Bar Chart)')

plt.xlabel('Sentiment')

plt.ylabel('Count')

plt.show()

print("Sentiment:", sentiment)
