#include "LeitnerSystem.h"

#include <algorithm>

LeitnerCard::LeitnerCard(int id, int initialLevel)
    : wordId(id),
      level(std::max(LeitnerSystem::MIN_LEVEL,
                     std::min(initialLevel, LeitnerSystem::MAX_LEVEL))),
      correctCount(0),
      wrongCount(0)
{
}

void LeitnerSystem::addCard(const LeitnerCard& card)
{
    cards[card.wordId] = card;
    cards[card.wordId].level = std::max(
        MIN_LEVEL,
        std::min(cards[card.wordId].level, MAX_LEVEL)
    );
}

bool LeitnerSystem::updateResult(int wordId, bool remembered)
{
    auto it = cards.find(wordId);

    if (it == cards.end())
        return false;

    LeitnerCard& card = it->second;

    if (remembered)
    {
        ++card.correctCount;
        card.level = std::min(card.level + 1, MAX_LEVEL);
    }
    else
    {
        ++card.wrongCount;
        card.level = std::max(card.level - 1, MIN_LEVEL);
    }

    return true;
}

const LeitnerCard* LeitnerSystem::getCard(int wordId) const
{
    auto it = cards.find(wordId);
    return it == cards.end() ? nullptr : &it->second;
}

std::vector<LeitnerCard> LeitnerSystem::getCardsAtLevel(int level) const
{
    std::vector<LeitnerCard> result;

    for (const auto& entry : cards)
    {
        if (entry.second.level == level)
            result.push_back(entry.second);
    }

    return result;
}

std::vector<LeitnerCard> LeitnerSystem::getWeakCards(int maximumLevel) const
{
    std::vector<LeitnerCard> result;

    for (const auto& entry : cards)
    {
        if (entry.second.level <= maximumLevel)
            result.push_back(entry.second);
    }

    return result;
}
