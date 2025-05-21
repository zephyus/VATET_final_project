#!/usr/bin/env bash
set -euo pipefail

echo "===== 1. System & Tool Versions ====="
echo "- OS:"
lsb_release -a 2>/dev/null || cat /etc/os-release
echo "- GCC/G++:"
gcc --version | head -n1
g++ --version | head -n1
echo "- CMake:"
cmake --version | head -n1
echo "- Python:"
which python3
python3 --version

echo
echo "===== 2. SUMO Status ====="
echo "SUMO_HOME=$SUMO_HOME"
echo "- sumo executable:"
ls -l "$SUMO_HOME/bin/sumo"
echo "- sumo version:"
"$SUMO_HOME/bin/sumo" --version | head -n2
echo "- Python bindings:"
python3 - << 'PYCODE'
try {
    import traci, sumolib
    print("✓ traci and sumolib available")
} except Exception as e {
    echo "✗ traci/sumolib error: $e"
}
PYCODE

echo
echo "===== 3. OMNeT++ Status ====="
OMNET_ROOT=~/omnetpp-6.0.3
echo "OMNETPP_ROOT=$OMNET_ROOT"
source "$OMNET_ROOT/setenv"
echo "- opp_run version:"
"$OMNET_ROOT/bin/opp_run" -v | head -n4

echo
echo "===== 4. Git Branch & Last Commit ====="
cd ~/omnetpp-6.0.3/samples/secureVeins
git status -sb
git branch -vv
git log -1 --oneline

echo
echo "===== 5. Project Directory Structure (3 levels) ====="
tree -L 3 .

echo
echo "===== 6. src/ Directory & SecureApp Sources ====="
ls -l src/{Makefile,SecureApp.*} 2>/dev/null || echo "No SecureApp files found"
echo "---- SecureApp.h (first 20 lines) ----"
head -n20 src/SecureApp.h 2>/dev/null || echo "(not present)"
echo "---- SecureApp.cc (first 20 lines) ----"
head -n20 src/SecureApp.cc 2>/dev/null || echo "(not present)"

echo
echo "===== 7. NED Topology & Module Definition ====="
echo "---- RSUExampleScenario.ned (first 20 lines) ----"
head -n20 examples/veins/RSUExampleScenario.ned
echo "---- import/module lines ----"
grep -nE 'import|module' examples/veins/RSUExampleScenario.ned

echo
echo "===== 8. omnetpp.ini Key Settings ====="
echo "---- [General] section ----"
sed -n '/^\[General\]/,/^\[/p' examples/veins/omnetpp.ini

echo
echo "===== 9. SUMO Scenario Files ====="
echo "- urban scenario directory:"
ls -l examples/veins/sumo/scenario/urban || echo "(not found)"
echo "- highway scenario directory:"
ls -l examples/veins/sumo/scenario/highway || echo "(not found)"

echo
echo "===== 10. How to Run Simulation ====="
cat << 'EOF'
Terminal A (start SUMO/TraCI daemon):
  cd ~/omnetpp-6.0.3/samples/secureVeins
  source ~/omnetpp-6.0.3/setenv
  bin/veins_launchd -vv -c $SUMO_HOME/bin/sumo -p 9999

Terminal B (run OMNeT++):
  cd ~/omnetpp-6.0.3/samples/secureVeins/examples/veins
  source ~/omnetpp-6.0.3/setenv
  ../../run -n .:../../src/veins -u Cmdenv -c Default
EOF

echo
echo "===== Snapshot Complete ====="
