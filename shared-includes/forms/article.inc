<fieldset id="journal-freeform-fieldset" class="rows">
    <legend>Lehden tiedot</legend>
    <ol id="journal-freeform-fields">
        <li>
            <label for="title">Nimeke:</label>
            <input type="text" name="title" id="title" value="[% whole.value.other.title %]" />
        </li>
        <li>
            <label for="volume">Osa:</label>
            <input type="text" name="volume" id="volume" value="[% whole.value.other.volume %]" />
        </li>
        <li>
            <label for="issue">Lehden numero:</label>
            <input type="text" name="issue" id="issue" value="[% whole.value.other.issue %]" />
        </li>
        <li>
            <label for="year">Vuosi:</label>
            <input type="text" name="year" id="year" value="[% whole.value.other.year %]" />
        </li>
        <li>
            <label for="issn">ISSN:</label>
            <input type="text" name="issn" id="issn" value="[% whole.value.other.issn %]" />
        </li>
    </ol>
</fieldset>
<fieldset id="article-freeform-fieldset" class="rows">
    <legend>Artikkelin tiedot</legend>
    <ol id="article-freeform-fields">
        <li>
            <label for="article_title">Artikkelin otsikko:</label>
            <input type="text" name="article_title" id="article_title" value="[% whole.value.other.article_title %]" />
        </li>
        <li>
            <label for="article_author">Artikkelin tekijä:</label>
            <input type="text" name="article_author" id="article_author" value="[% whole.value.other.article_author %]" />
        </li>
        <li>
            <label for="published_date">Julkaisupäivä:</label>
            <input type="text" name="published_date" id="published_date" value="[% whole.value.other.published_date %]" />
        </li>
        <li>
            <label for="pages">Sivuja:</label>
            <input type="text" name="pages" id="pages" value="[% whole.value.other.pages %]" />
        </li>
        <li>
            <label for="doi">DOI:</label>
            <input type="text" name="doi" id="doi" value="[% whole.value.other.doi %]" />
        </li>
    </ol>
</fieldset>
