/*
Purpose:
	This algorithm finds the largest possible combination of numbers in a list without header files.
	If a number is selected, its immediate neighbors cannot be selected.
Solution:
	This problem is solved by repeatedly dividing the dataset into alternating sequences and increasing the size of both until a sequence is selected.
	A sequence is selected when it becomes larger than the other and is surrounded by the other sequence or reaches a predefined point.
Inputs:
	To use, insert data into data[] and adjust data[] and answers[] array size.
*/
extern "C" int printf(const char *one, ...);
int data[1], answers[1];
int adjust, distance, i, maxloop, possiblemaxloop, redo, total[2], counter = sizeof(data)/4;
int main()
{
	while (i < counter)
	{
		//Determines the inputs for the next i < counter loop
		for (;answers[i] != 0; i++);
		for(maxloop = 0; maxloop < counter - i, (data[i + maxloop] * 1.1 > data[i + maxloop + 1] || data[i + maxloop] * 0.9 < data[i + maxloop + 1]) && data[i + maxloop] > 0; maxloop++);
		if (data[i] <= 0 || answers[i + 1] == 2) answers[i] = 1;
		else
		{
			for (redo = 0; redo != 2; redo++)
			{
				//Determines if the sequence should start with total[0] or total[1]
				if ((i == 0 || answers[i - 1] == 1) && redo == 0)
				{
					distance = 0;
					total[1] = 0;
					adjust = 0;
					redo = 0;
				}
				else
				{
					distance = 1;
					total[1] = data[i];
					adjust = 1;
					redo = 1;
				}
				//Aggregates the relevant sum of each data point into total[]
				for (total[0] = 0; distance < maxloop && answers[i + distance] == 0; distance += 2)
				{
					if (answers[i + distance] == 0)total[0] += data[i + distance];
					if (answers[i + distance + 1] == 0) total[1] += data[i + distance + 1];
					//Determines if total[0] is larger than total[1], and if it is, it records the sequence into answers[]
					if (total[0] >= total[1])
					{
						if (adjust == 1) answers[i] = 1;
						for (;adjust <= distance; adjust += 2)
						{
							if (answers[i + adjust + 1] != 2) answers[i + adjust] = 2;
							else 
								{
									answers[i + adjust] = 1;
									goto loopend;
								}
							answers[i + adjust + 1] = 1;
						}
						goto loopend;
					}
					//Determines if total[1], excluding the most recent point, is larger than total[0], and if it is, it records the sequence into answers[]
					else if (total[1] - data[i + distance + 1] >= total[0] && adjust == 0)
					{
						for (; adjust <= distance; adjust += 2)
						{
							answers[i + adjust] = 1;
							if (answers[i + adjust + 1] == 0 && answers[i + adjust + 2] != 2 && adjust < distance) answers[i + adjust + 1] = 2;
							else goto loopend;
						}
						answers[i + adjust] = 1;
						goto loopend;
					}
				}
			}
		}
		loopend:;
		i++;
	}
//Output
for (i = 0; i < counter; i++) printf("i: %i,	Data: %i,	Answers: %i\n", i, data[i], answers[i]);
return(0);
}