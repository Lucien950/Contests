#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int permute_length, letter_count, string_length;
		cin >> permute_length >> letter_count >> string_length;
		string s;
		cin >> s;

		int         segment_count                    = 0;
		bool        has_touched_letter[letter_count] = { false };
		int         touched_letters                  = 0;
		vector<int> segment_starts;
		for (int i = string_length - 1; i >= 0; i--)
		{
			if (const int letter_index = s[i] - 'a'; !has_touched_letter[letter_index])
			{
				has_touched_letter[letter_index] = true;
				touched_letters++;
			}

			if (touched_letters == letter_count)
			{
				segment_count++;
				fill_n(has_touched_letter, letter_count, false);
				touched_letters = 0;
				segment_starts.push_back(i);
			}

			if (segment_count == permute_length)
				break;
		}

		const bool reached_end = segment_count == permute_length;
		cout << (reached_end ? "YES" : "NO") << endl;
		if (reached_end)
			continue;
		// todo remember to pad the start and end??
		string counter_example;
		// for (int i = 0; (i < string_length) && (touched_letters < letter_count - 1); i++)
		// {
		// 	if (const int letter_index = s[i] - 'a'; !has_touched_letter[letter_index])
		// 	{
		// 		has_touched_letter[letter_index] = true;
		// 		touched_letters++;
		// 	}
		// }
		const int pad_length = permute_length - segment_count - 1;
		for (int i = 0; i < pad_length; i++)
		{
			counter_example += 'a';
		}
		for (int j = 0; j < letter_count; j++)
		{
			if (!has_touched_letter[j])
			{
				counter_example += static_cast<char>(j + 'a');
				break;
			}
		}
		for (int i = 0; i < segment_count; i++)
		{
			const int get_char_index = segment_starts[segment_count - i - 1];
			counter_example += s[get_char_index];
		}

		cout << counter_example << endl;
	}
}