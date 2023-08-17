/**
 * @file main.cpp
 * @brief Main entry point for the 3D structure compression program.
 *
 * This file contains the main function that initializes the StreamProcessor
 * class and starts the processing of the input stream for compressing 3D structures.
 */

#include <fstream>
#include <string.h>
#include <iostream>
#include <chrono>
#include "stream_processor.h"

/**
 * @brief Main function to run the 3D structure compression program.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Returns 0 on successful execution, 1 if incorrect usage.
 *
 * The main function takes the input file name as a command-line argument,
 * initializes the StreamProcessor object, and starts the stream processing.
 * The input file should contain the uncompressed 3D structure data.
 */
int main(int argc, char *argv[]) {

    // SPEEED
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bool timerEnabled = (argc > 1 && strcmp(argv[1], "-t") == 0);

    if (timerEnabled) {
        // Start the timer
        auto start = std::chrono::high_resolution_clock::now();

        // Initialize and process the stream
        StreamProcessor myStreamProcessor;
        myStreamProcessor.StartProcessing();

        // Stop the timer
        auto stop = std::chrono::high_resolution_clock::now();

        // Compute the duration
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
    } else {
        // Initialize and process the stream without timing
        StreamProcessor myStreamProcessor;
        myStreamProcessor.StartProcessing();
    }

    return 0;
}
