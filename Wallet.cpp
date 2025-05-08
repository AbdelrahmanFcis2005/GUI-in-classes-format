
class Wallet {
public:
	string currentUser;
	set<User> users;
	list<Transaction> trans;
	list<Request> requests;

	User* find_user(string username) {
		// Write your code here
	}

	bool delete_user(string username) {
		// Write your code here
	}

	bool add_user(string username, string password, bool status, float balance, string phone) {
		// Write your code here
	}

	bool check_user(string username, string password) {
		// Write your code here
	}

	void display_user(string username) {
		// Write your code here
	}

	bool edit(string username, string field, string value) {
		// Write your code here
	}

	bool make_trans(string sender, string recipient, float amount) {
		// Write your code here
	}

	int get_all_users() {
		// Write your code here
	}

	void get_all_trans() {
		// Write your code here
	}

	void get_all_trans(string username) {
		// Write your code here
	}

	Request* find_requests(int id) {
		// Write your code here
	}

	bool create_request(string requester, string sender, float amount) {
		// Write your code here
	}

	bool finalize_request(int id) {
		// Write your code here
	}

	bool delete_request(int id) {
		// Write your code here
	}

	void get_all_requests() {
		// Write your code here
	}

	int get_all_requests(string username) {
		// Write your code here
	}

	int n_requests(string username) {
		// Write your code here
	}

	bool save() {
		// Write your code here
	}

	bool load() {

		// Write your code here
	}

	// Seperate a string into a vector based on provided Delimiter
	vector<string> getWords(string s) {
		vector<string> res;
		string delim = "\t";
		string token = "";
		for (int i = 0; i < s.size(); i++) {
			bool flag = true;
			for (int j = 0; j < delim.size(); j++) {
				if (s[i + j] != delim[j]) flag = false;
			}
			if (flag) {
				if (token.size() > 0) {
					res.push_back(token);
					token = "";
					i += delim.size() - 1;
				}
			}
			else {
				token += s[i];
			}
		}
		res.push_back(token);
		return res;
	}

	// Convert String to Bool
	bool string_to_bool(string string) {
		if (string == "true" || string == "1") {
			return true;
		}
		else if (string == "false" || string == "0") {
			return false;
		}
	}

	// Return a string of the date and time at the call moment
	string datetime_now() {
		time_t now = time(0);
		char buffer[80];

		struct tm timeinfo;
		localtime_s(&timeinfo, &now);

		// Format time to "YYYY-MM-DD HH:MM:SS"
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);

		return string(buffer);  // Return the formatted string
	}
};

