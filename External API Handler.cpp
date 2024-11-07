class ReverbException : public std::exception {
public:
    explicit ReverbException(const std::string& message) : msg(message) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

// Inside the ReverbRuntime methods, throw specific exceptions
void ReverbRuntime::executeGauge(int base, int stretch) {
    if (base < 0 || stretch < 0) {
        throw ReverbException("Base and stretch values must be non-negative.");
    }
    // Existing implementation...
}
class APIHandler {
public:
    explicit APIHandler(const std::string& baseUrl) : baseUrl(baseUrl) {}

    std::string getData(const std::string& endpoint) {
        // Implement API data fetching
    }

private:
    std::string baseUrl;
};

class APIHandler {
public:
    explicit APIHandler(const std::string& baseUrl) : baseUrl(baseUrl) {}

    std::string getData(const std::string& endpoint) {
        // Implementation to fetch data from the API
        // Use a networking library to handle HTTP requests
    }

private:
    std::string baseUrl;
};

#include <string>
#include <unordered_map>
#include <curl/curl.h> // Assuming cURL is used for API calls

class APIHandler {
public:
    APIHandler() {
        curl_global_init(CURL_GLOBAL_DEFAULT); // Initialize cURL
    }

    ~APIHandler() {
        curl_global_cleanup(); // Clean up cURL
    }

    // Sets up authentication for API requests
    void setAuth(const std::string& key, const std::string& value) {
        authHeaders[key] = value;
    }

    // Make a GET request to an external API
    std::string getRequest(const std::string& url) {
        CURL* curl = curl_easy_init();
        std::string response;

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            // Set headers
            struct curl_slist* headers = nullptr;
            for (const auto& header : authHeaders) {
                std::string headerString = header.first + ": " + header.second;
                headers = curl_slist_append(headers, headerString.c_str());
            }
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            // Perform the request
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "cURL GET request failed: %s\n", curl_easy_strerror(res));
            }

            // Clean up
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        return response;
    }

    // Make a POST request to an external API
    std::string postRequest(const std::string& url, const std::string& postData) {
        CURL* curl = curl_easy_init();
        std::string response;

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            // Set headers
            struct curl_slist* headers = nullptr;
            for (const auto& header : authHeaders) {
                std::string headerString = header.first + ": " + header.second;
                headers = curl_slist_append(headers, headerString.c_str());
            }
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            // Perform the request
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "cURL POST request failed: %s\n", curl_easy_strerror(res));
            }

            // Clean up
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        return response;
    }

private:
    // Helper callback to write API response data to a string
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
        size_t totalSize = size * nmemb;
        userData->append((char*)contents, totalSize);
        return totalSize;
    }

    std::unordered_map<std::string, std::string> authHeaders;
};
