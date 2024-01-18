#!/bin/bash

convert "$1" "$2" -geometry "100%x100%+$3+$4" -composite "signed.$1"