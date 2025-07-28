#!/bin/bash
ulimit -v 1000  # Limite à 10 Mo de mémoire virtuelle
exec ./push_swap 10 11
