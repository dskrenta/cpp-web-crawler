// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Crawler.h

#ifndef CRAWLER_H
#define CRAWLER_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <queue>
#include <atomic>
#include <thread>
#include <sstream>

#include "ThreadPool.h"
// #include "WebGraph.h"

using namespace std;

class Crawler {
    public:
        Crawler(
            unordered_set <string> roots,
            const string &hostWhitelistFilename,
            const string &hostBlacklistFilename,
            const string &destDir,
            const int numPagesToCrawl,
            const size_t concurrencyLimit
        );
        ~Crawler();

        void readFileToSet(const string &filename, unordered_set <string> set);

        void startCrawl();
        void endCrawl();
        void logCrawlData();
        void parseUrls(string);

    private:
        unordered_set <string> roots;
        unordered_set <string> hostWhitelist;
        unordered_set <string> hostBlacklist;
        unordered_set <string> seenUrls;
        queue <string> crawlQueue;
        ThreadPool pool;
        // WebGraph webGraph;
        atomic <int> numPagesCrawled {0};
        string dataDirectory;
        hash <string> h;
};
#endif // CRAWLER_H
