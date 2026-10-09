#ifndef LEITNER_SYSTEM_H
#define LEITNER_SYSTEM_H

#include <map>
#include <vector>

// A flashcard's mastery level is always in the range 1..5.
struct LeitnerCard
{
    int wordId;
    int level;
    int correctCount;
    int wrongCount;

    LeitnerCard(
        int id = 0,
        int initialLevel = 1
    );
};

class LeitnerSystem
{
private:
    std::map<int, LeitnerCard> cards;

public:
    static const int MIN_LEVEL = 1;
    static const int MAX_LEVEL = 5;

    void addCard(const LeitnerCard& card);
    bool updateResult(int wordId, bool remembered);
    const LeitnerCard* getCard(int wordId) const;
    std::vector<LeitnerCard> getCardsAtLevel(int level) const;
    std::vector<LeitnerCard> getWeakCards(int maximumLevel = 2) const;
};

#endif
