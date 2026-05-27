#problem approach 

let high is the highest number for given digit as well as for low

assume  palindrome = 0 for comparision

let i be high and goes to low &&
j starts from i and goes toward low:
	product = i*j
	check if product is greater than palindrome
		if yes then check if product is palindrome number:
		store product into palindrome

>> why product > palindrome ? -- to get the largest palindrome evem if loop run again , it  will fail for condition  and with this we get largest palindrome




