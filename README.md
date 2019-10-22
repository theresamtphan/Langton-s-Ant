# Langton-s-Ant

This program simulates Langton's Ant. The Langton's Ant simulation can be considered as a cellular automation, a model that has simple rules governing its replication or destruction.

The rule of Langton’s Ant is very simple: the ant is placed onto the board that is filled with white spaces, and starts moving forward. For each step forward, the Langton’s ant will follow 2 rules:

    If the ant is on a white space, turn right 90 degrees and change the space to black.
    If the ant is on a black space, turn left 90 degrees and change the space to white.

After that the ant moves to the next step and continue moving forward. The ant will follow these rules, and continue moving around the board, until the number of steps runs out.
