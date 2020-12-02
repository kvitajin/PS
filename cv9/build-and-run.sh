#!/bin/bash

# Make sure all paths are relative to the script location
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"

echo ""
echo "----------------------------"
echo "Checking all dependencies..."
echo "----------------------------"
yarn --cwd server install
yarn --cwd client install

echo ""
echo "----------------------------"
echo "Building client..."
echo "----------------------------"
yarn --cwd client build --silent

echo ""
echo "----------------------------"
echo "Running server"
echo "----------------------------"
yarn --cwd server start