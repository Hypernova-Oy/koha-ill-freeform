<fieldset id="book-freeform-fieldset" class="rows">
    <legend>Kirjan tiedot</legend>
    <ol id="publication-freeform-fields">
        <li>
            <label for="title">Nimeke:</label>
            <input type="text" name="title" id="title" value="[% whole.value.other.title %]" />
        </li>
        <li>
            <label for="author">Tekijä:</label>
            <input type="text" name="author" id="author" value="[% whole.value.other.author %]" />
        </li>
        <li>
            <label for="editor">Toimittaja:</label>
            <input type="text" name="editor" id="editor" value="[% whole.value.other.editor %]" />
        </li>
        <li>
            <label for="publisher">Julkaisija:</label>
            <input type="text" name="publisher" id="publisher" value="[% whole.value.other.publisher %]" />
        </li>
        <li>
            <label for="published_place">Julkaisupaikka:</label>
            <input type="text" name="published_place" id="published_place" value="[% whole.value.other.published_place %]" />
        </li>
        <li>
            <label for="year">Vuosi:</label>
            <input type="text" name="year" id="year" value="[% whole.value.other.year %]" />
        </li>
        <li>
            <label for="part_edition">Painos:</label>
            <input type="text" name="part_edition" id="part_edition" value="[% whole.value.other.part_edition %]" />
        </li>
        <li>
            <label for="volume">Osa:</label>
            <input type="text" name="volume" id="volume" value="[% whole.value.other.volume %]" />
        </li>
        <li>
            <label for="isbn">ISBN:</label>
            <input type="text" name="isbn" id="isbn" value="[% whole.value.other.isbn %]" />
        </li>
        <li>
            <label for="doi">DOI:</label>
            <input type="text" name="doi" id="doi" value="[% whole.value.other.doi %]" />
        </li>
    </ol>
</fieldset>
