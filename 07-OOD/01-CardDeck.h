enum Suit {
    Spade (0),
    Diamond (1),
    Heart (2),
    Club (4)
};

class Card {
    protected:
    int Value;
    Suit Suit;
    bool ColorCard;

};

class SpadeCard : Card {

};

class DiamondCard : Card {

};


class HeartCard : Card {

};


class ClubCard : Card {

};

class Deck {
    Card[52] Cards;

    public:
    Card GetCard(int value, Suite suite);
    Card[] Suffle();
};

class Hand {
    Card* CardsInHand;
    int HandValue;
};

class Player : Hand {
    void DecideMove();
};

class Dealer : Player {
    void DealCard();
};

class Blackjack {
    Deck[] BaseDeck;
    Dealer Dealer;
    Player[] Players;
    Card[] OpenCards;
};
