import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.posset = set()
        self.negset = set()

        file = open(positives, "r")
        for line in file:
            if not line.startswith(';'):
                self.posset.add(line.rstrip("\n"))
        file.close()

        file = open(negatives, "r")
        for line in file:
            if not line.startswith(';'):
                self.negset.add(line.rstrip("\n"))
        file.close()


    def Analyzer(self, text):
        """Analyze text for sentiment, returning its score."""
        """ we call the class METHOD TweetTokenizer and assign it to
            an internal function called the Tokenizer """
        Tokenizer = nltk.tokenize.TweetTokenizer(
            preserve_case=True, reduce_len=True, strip_handles=True)
        """ here we create our tokens for the function """
        Tokens = Tokenizer.tokenize(text)
        score = 0
        for token in Tokens:
            if token.lower() in self.posset:
                score += 1
            elif token.lower() in self.negset:
                score -= 1
        return score
