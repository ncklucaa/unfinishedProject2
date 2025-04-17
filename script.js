document.getElementById("fileInput").addEventListener("change", function ()
{
    const file = this.files[0];
    if (!file) return;

    const reader = new FileReader();
    reader.onload = function (e)
    {
        document.getElementById("logOutput").textContent = e.target.result;
    };
    reader.readAsText(file);
});
