bool check_number (string str) { // Function to validate input
  for (int i = 0; i < str.length(); i++)
    if (isdigit(str[i]) == false) return false;
  return true;
}