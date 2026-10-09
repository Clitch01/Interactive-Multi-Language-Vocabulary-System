#include "LeitnerSystem.h"

#include <cassert>

int main()
{
    LeitnerSystem system;
    system.addCard(LeitnerCard(1, 1));

    assert(system.updateResult(1, true));
    assert(system.getCard(1)->level == 2);

    assert(system.updateResult(1, false));
    assert(system.getCard(1)->level == 1);

    system.addCard(LeitnerCard(2, 5));
    assert(system.updateResult(2, true));
    assert(system.getCard(2)->level == 5);

    system.addCard(LeitnerCard(3, 1));
    assert(system.updateResult(3, false));
    assert(system.getCard(3)->level == 1);

    assert(!system.updateResult(999, true));
    return 0;
}
