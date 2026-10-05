/**
 * @file test_trash_fronts.cpp
 * @brief A fire front put in the trash twice is deleted once.
 * @copyright Copyright (C) 2025 ForeFire, Fire Team, SPE, CNRS/Universita di Corsica.
 * @license This program is free software; See LICENSE file for details. (See LICENSE file).
 */

#include "doctest/doctest.h"

#include "model_sandbox.h"

#include "FireDomain.h"
#include "FireFront.h"

using libforefire::FireDomain;
using libforefire::FireFront;
using ff_test::ModelSandbox;

TEST_SUITE("fire fronts") {

TEST_CASE("a front trashed twice survives the domain's destruction") {
    ModelSandbox sandbox;
    FireDomain* domain = sandbox.fireDomain();
    FireFront* front = new FireFront(domain);

    // FireFront::merge can trash a front that is already in the trash.
    domain->addToTrashFronts(front);
    domain->addToTrashFronts(front);
    CHECK(front->getNumFN() == 0);
}

}
