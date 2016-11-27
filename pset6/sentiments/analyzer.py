import nltk
import os


class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives="positive-words.txt", negatives="negative-words.txt"):
        """Initialize Analyzer."""
        
        self.tokenizer = nltk.tokenize.TweetTokenizer()

        self.positives = set()
        with open(positives) as lines:
            for line in lines:
                line = line.strip()
                if line and not line.startswith(";"):
                    self.positives.add(line)
                    
        self.negatives = set()
        with open(negatives) as lines:
            for line in lines:
                line =line.strip()
                if line and not line.startswith(";"):
                    self.negatives.add(line)
    
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        tokens = self.tokenizer.tokenize(text)
        
        score = 0
        
        for token in tokens:
            token = token.lower()
            if token in self.positives:
                score += 1
            if token in self.negatives:
                score -= 1    
        
        return score
