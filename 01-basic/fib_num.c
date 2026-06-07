/*Two players are playing an interesting game. Initially, there are N matches on the table. The first player may take any number of matches, but not all of them. The second player may then take at most twice as many matches as the first player took. Next, the first player may take at most twice as many matches as the second player took, and so on. The player who takes the last match wins.

Game 1:
11 matches. The first player takes 4. The second player may take up to 8 and takes 7, winning the game.
Game notation: 11.4,7!

Game 2:
11.3,3,5!

Game 3:
11.3,2,1,1,1,1,2!

Your submission should consist of a function that, given:
- total: the total number of matches remaining,
- possible: the maximum number of matches that may be taken on this turn, returns the number of matches it wants to take.
Naturally, your function should always make the optimal move.
If no optimal move exists (i.e., every available move eventually loses), it is reasonable to take one match and give the opponent a chance to make a mistake. */

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

unsigned fib_arr[32] = {0};

unsigned fill_fib_arr(unsigned total) {
        int i;

        fib_arr[0] = 1;         // fib(2)
        fib_arr[1] = 2;         // fib(3)

        i = 2;
        while (fib_arr[i - 1] <= total) {
                fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
                i++;
        }
        return i;
}

int next_turn(int total, int possible) {
	int count = fill_fib_arr(total);
	int answer = 1;

	if (possible >= total)
		return total;

	for (int i = count - 1; i >= 0; i--) {
		if (fib_arr[i] <= total) {
			 total = total - fib_arr[i];
			 answer = fib_arr[i];
		}
	}

	if (answer <= possible)
		return answer;

	return 1;
}
