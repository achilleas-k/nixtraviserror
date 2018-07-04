import os
from subprocess import Popen, PIPE
import tempfile

from .compile import maketests


BINDIR = tempfile.mkdtemp(prefix="nixpy-tests-")

maketests(BINDIR)


def runcpp(command, *args):
    cmdbin = os.path.join(BINDIR, command)
    cmdargs = [cmdbin]
    cmdargs.extend(args)
    proc = Popen(cmdargs, stdout=PIPE, stderr=PIPE)
    proc.wait()
    stdout = proc.stdout.read().decode()
    stderr = proc.stderr.read().decode()
    # print(stdout)
    # print(stderr)
    if proc.returncode:
        raise ValueError(stdout+stderr)


def test_full_file_read():
    nixfilepath = "filetest-readpy.nix"
    runcpp("writefullfile", nixfilepath)
