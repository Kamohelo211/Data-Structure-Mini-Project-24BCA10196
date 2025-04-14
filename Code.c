#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char currencyPair[7]; 
    double bidPrice;
    double askPrice;
    double lastPrice;
    char timestamp[20]; 
} ForexData;

ForexData* createForexData(const char* pair, double bid, double ask, double last, const char* time) {
    ForexData* newData = (ForexData*)malloc(sizeof(ForexData));
    if (newData == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(newData->currencyPair, pair, sizeof(newData->currencyPair) - 1);
    newData->currencyPair[sizeof(newData->currencyPair) - 1] = '\0';
    newData->bidPrice = bid;
    newData->askPrice = ask;
    newData->lastPrice = last;
    strncpy(newData->timestamp, time, sizeof(newData->timestamp) - 1);
    newData->timestamp[sizeof(newData->timestamp) - 1] = '\0';
    return newData;
}

void printForexData(const ForexData* data) {
    if (data != NULL) {
        printf("Currency Pair: %s\n", data->currencyPair);
        printf("Bid Price: %.5f\n", data->bidPrice);
        printf("Ask Price: %.5f\n", data->askPrice);
        printf("Last Price: %.5f\n", data->lastPrice);
        printf("Timestamp: %s\n", data->timestamp);
    }
}
void freeForexData(ForexData* data) {
    if (data != NULL) {
        free(data);
    }
}

int main() {
    
    ForexData* data = createForexData("EURUSD", 1.12345, 1.12355, 1.12350, "2025-04-11 10:00:00");
    printForexData(data);
    freeForexData(data);
    return 0;
}
