import subprocess
from rich.console import Console


error_console = Console(stderr=True, style="bold red")


def run_command(cmd):
    """Runs shell commands from the arguments and returns the respective outputs

    Args:
        cmd (_type_): subprocess command to run
    """
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    if result.returncode != 0:
        raise Exception(f"Command failed with error: {result.stderr}")
    return result.stdout.strip()