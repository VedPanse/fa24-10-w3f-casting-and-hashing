#!/bin/bash

gcc -I/opt/local/include -L/opt/local/lib -lcrypto -lssl hash.c
