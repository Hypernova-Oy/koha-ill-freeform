[% SET koha_version = Koha.Version %]
[% IF whole.error %]
[% IF whole.status == 'missing_identifier' %]
<p><em>Please Note:</em> Mandatory field Identifier is missing.</p>
[% ELSIF whole.status == 'missing_branch' %]
<p><em>Please Note:</em> Branch is a mandatory field.</p>
[% ELSIF whole.status == 'invalid_borrower' %]
<p><em>Please Note:</em> The borrower details you entered are invalid.</p>
[% ELSIF whole.status == 'invalid_branch' %]
<p><em>Please Note:</em> The branch you chose is invalid.</p>
[% ELSE %]
<p>Unhandled error</p>
[% END %]
[% END %]

[% IF whole.stage == "form" %]
<form id="create_form" method="POST" action=[% here %]>
  [% INCLUDE 'csrf-token.inc' %]
  <fieldset class="rows">
    <legend>Tiedot</legend>
    <ol id="general-freeform-fields">
      <li>
        <label class="required" for="type">Type:</label>
        <select name="type" id="type">
          <option value=""/>
          [% IF whole.value.other.type.lower == "article" %]
          <option value="article" selected="selected">Artikkeli</option>
          [% ELSE %]
          <option value="article">Artikkeli</option>
          [% END %]
          [% IF whole.value.other.type.lower == "resource" %]
          <option value="resource" selected="selected">CD</option>
          [% ELSE %]
          <option value="resource">CD</option>
          [% END %]
          [% IF whole.value.other.type.lower == "journal" %]
          <option value="journal" selected="selected">Kausijulkaisu</option>
          [% ELSE %]
          <option value="journal">Kausijulkaisu</option>
          [% END %]
          [% IF whole.value.other.type.lower == "book" %]
          <option value="book" selected="selected">Kirja</option>
          [% ELSE %]
          <option value="book">Kirja</option>
          [% END %]
          [% IF whole.value.other.type.lower == "dvd" %]
          <option value="dvd" selected="selected">Videotallenne</option>
          [% ELSE %]
          <option value="dvd">Videotallenne</option>
          [% END %]
          [% IF whole.value.other.type.lower == "other" %]
          <option value="other" selected="selected">Muu</option>
          [% ELSE %]
          <option value="other">Muu</option>
          [% END %]
        </select>
      </li>
    </ol>
  </fieldset>
  [% cwd = whole.cwd %]
  [% type = whole.value.other.type %]
  [% IF type %]
      [% INCLUDE "${cwd}/shared-includes/forms/${type}.inc" %]
  [% END %]
  [% INCLUDE "${cwd}/shared-includes/custom_fields.inc" %]
  <fieldset class="rows">
    <legend>Asiakkaan valinnat</legend>
    <ol>
      <li>
        <label class="required" for="cardnumber">
          Kortinnumero, käyttäjätunnus tai sukunimi
        </label>
        <input type="text" name="cardnumber" id="cardnumber" autocomplete="off"
               type="text" value="" />
      </li>
      <li>
        <label class="required" for="branchcode">Kohdekirjasto:</label>
        <select id="branchcode" name="branchcode">
          <option value="" />
          [% FOREACH branch IN branches %]
            <option value="[% branch.branchcode %]">
              [% branch.branchname %]
            </option>
          [% END %]
        </select>
      </li>
    </ol>
  </fieldset>
  <fieldset class="action">
    <input id="ill-submit" type="submit" value="Luo kaukolainapyyntö" disabled />
    <a class="cancel" href="/cgi-bin/koha/ill/ill-requests.pl">Peruuta</a>
  </fieldset>
  <input type="hidden" name="method" value="create" />
  <input type="hidden" name="stage" value="form" />
  <input type="hidden" name="backend" value="FreeForm" />
</form>
[% BLOCK backend_jsinclude %]
<script type="text/javascript">
    // <![CDATA[]
    [% INCLUDE "${cwd}/shared-includes/shared.js" %]
    // Require a username and branch selection
    document.addEventListener('DOMContentLoaded', function(){
        $('#create_form #cardnumber, #create_form #branchcode').change(function() {
            var comp = ['#cardnumber','#branchcode'].filter(function(id) {
                return $(id).val().length > 0;
            });
            $('#ill-submit').attr('disabled', comp.length < 2);
        });
      /* Maintain patron autocomplete compatibility across versions */
      [% IF koha_version.major <= 22 && koha_version.minor < 11 %]
      $('#create_form #cardnumber').autocomplete({
          source: "/cgi-bin/koha/circ/ysearch.pl",
          minLength: 3,
          select: function( event, ui ) {
              var field = ui.item.cardnumber;
              $('#create_form #cardnumber').val(field)
              return false;
          }
      })
      .data( "ui-autocomplete" )._renderItem = function( ul, item ) {
          return $( "<li></li>" )
          .data( "ui-autocomplete-item", item )
          .append( "<a>" + item.surname + ", " + item.firstname + " (" + item.cardnumber + ") <small>" + item.address + " " + item.city + " " + item.zipcode + " " + item.country + "</small></a>" )
          .appendTo( ul );
      };
      [% ELSE %]
      patron_autocomplete(
        $('#create_form #cardnumber'),
        {
          'on-select-callback': function( event, ui ) {
            $("#create_form #cardnumber").val( ui.item.cardnumber );
            return false;
          }
        }
      );
      [% END %]        
    });
    // ]]>
</script>
[% END %]

[% ELSIF whole.stage == "borrowers" %]
<!-- We need to clarify the borrower that has been requested. -->
<h2>Borrower selection</h2>
<form method="POST" action=[% here %]>
  [% FOREACH prop IN whole.value.other.keys %]
    [% IF prop != 'custom_key' &&  prop != 'custom_value' && prop != 'cardnumber' %]
    <input type="hidden" name="[% prop %]" value="[% whole.value.other.$prop %]">
    [% END %]
  [% END %]
  [% keys = whole.value.other.custom_key.split('\0') %]
  [% values = whole.value.other.custom_value.split('\0') %]
  [% i = 0 %]
  [% FOREACH key IN keys %]
    <input type="hidden" name="custom_key" value="[% key %]">
    <input type="hidden" name="custom_value" value="[% values.$i %]">
  [% i = i + 1 %]
  [% END %]
  <fieldset class="rows">
    <legend>Available borrowers for surname [% surname %]</legend>
    [% FOREACH opt IN whole.value %]
    [% IF opt.key == "brw" %]
    <ol>
      <li>
        <label class="required" for="brw">Borrower</label>
        <select name="cardnumber" id="cardnumber">
          <option value=""></option>
          [% FOREACH brw IN opt.value %]
          <option value="[% brw.cardnumber %]">
            [% brw.firstname %] [% brw.surname %] ([% brw.cardnumber %])
          </option>
          [% END %]
        </select>
      </li>
    </ol>
    [% END %]
    [% END %]
  </fieldset>
  <fieldset class="action">
    <input type="submit" value="Select"/>
    <a class="cancel" href=[% parent %]>Cancel</a>
  </fieldset>
</form>

[% ELSE %]
<p>Unknown stage.  This should not have happened.

[% END %]
